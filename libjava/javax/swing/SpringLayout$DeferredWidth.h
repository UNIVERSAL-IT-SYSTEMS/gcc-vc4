
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_SpringLayout$DeferredWidth__
#define __javax_swing_SpringLayout$DeferredWidth__

#pragma interface

#include <javax/swing/SpringLayout$DeferredDimension.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Component;
    }
  }
  namespace javax
  {
    namespace swing
    {
        class SpringLayout$DeferredWidth;
    }
  }
}

class javax::swing::SpringLayout$DeferredWidth : public ::javax::swing::SpringLayout$DeferredDimension
{

public:
  SpringLayout$DeferredWidth(::java::awt::Component *);
  virtual ::java::lang::String * toString();
  virtual jint getMaximumValue();
  virtual jint getMinimumValue();
  virtual jint getPreferredValue();
private:
  ::java::awt::Component * __attribute__((aligned(__alignof__( ::javax::swing::SpringLayout$DeferredDimension)))) c;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_SpringLayout$DeferredWidth__
