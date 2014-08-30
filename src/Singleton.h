// *******************************************************************
// The MIT License (MIT)
// 
// Copyright (c) 2014 Ioan "John" Rus
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// -------------------------------------------------------------------
//        File: Singleton.h
// Description: See class description.
//      Author: Ioan L. Rus
//        Date: May 5, 2014
//   Revisions: 
// -------------------------------------------------------------------
// INI Date        Description
// --- ----------- ---------------------------------------------------
// 
// *******************************************************************
#ifndef _SINGLETON_H_INCLUDED_
#define _SINGLETON_H_INCLUDED_

#include <mutex>

namespace Ioan
{
  namespace Thread
  {
    // Multithreaded singleton template base class.
    // Usage:
    //   1. Make the template a public base for your class.
    //   2. Use a private constructor for your class.
    //   3. Make the template a friend class.
    //
    // Example:
    //
    //      class MySingletonClass 
    //        : public Ioan::Thread::SingletonRef<MySingletonClass>
    //      {
    //      private:
    //        friend Ioan::Thread::SingletonRef<MySingletonClass>;
    //        MySingletonClass();
    //
    //      public:
    //        void DoWork() { ... }
    //      };
    //
    //      // Use the singleton as:
    //      MySingletonClass &s=MySingletonClass::GetInstance();
    //

    // Singleton that returns a ref
    template<typename T>
    class SingletonRef
    {
    public:
      static T &GetInstance()
      {
        static std::mutex m;
        std::lock_guard<std::mutex> lock(m);
        static T s;
        return s;
      }
    };

    // Singleton that returns a pointer
    template<typename T>
    class SingletonPtr
    {
    public:
      static T *GetInstance()
      {
        static std::mutex m;
        std::lock_guard<std::mutex> lock(m);
        static T s;
        return &s;
      }
    };

    // Singleton that calls static T::Create() and returns a ref.
    // T must privately implement Create() with this signature:
    //
    //   static T &Create();
    //
    template<typename T>
    class SingletonRefC
    {
    public:
      static T &GetInstance()
      {
        static std::mutex m;
        std::lock_guard<std::mutex> lock(m);
        static T &s=T::Create();
        return s;
      }
    };

  }
}

#define STATIC_INSTANCE_FUNCTION(T)\
static T &GetInstance()\
{\
  static std::mutex m;\
  std::lock_guard<std::mutex> lock(m);\
  static T s;\
  return s;\
}

#define STATIC_INSTANCE_FUNCTION_ARGS(T,...)\
  static T &GetInstance()\
{\
  static std::mutex m;\
  std::lock_guard<std::mutex> lock(m);\
  static T s(__VA_ARGS__);\
  return s;\
}

#endif // _SINGLETON_H_INCLUDED_
