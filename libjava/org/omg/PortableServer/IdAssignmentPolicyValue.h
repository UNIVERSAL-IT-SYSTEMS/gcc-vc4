
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_omg_PortableServer_IdAssignmentPolicyValue__
#define __org_omg_PortableServer_IdAssignmentPolicyValue__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace org
  {
    namespace omg
    {
      namespace PortableServer
      {
          class IdAssignmentPolicyValue;
      }
    }
  }
}

class org::omg::PortableServer::IdAssignmentPolicyValue : public ::java::lang::Object
{

public: // actually protected
  IdAssignmentPolicyValue(jint);
public:
  static ::org::omg::PortableServer::IdAssignmentPolicyValue * from_int(jint);
  virtual ::java::lang::String * toString();
  virtual jint value();
private:
  static const jlong serialVersionUID = 2024380631469554382LL;
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) _value;
public:
  static const jint _USER_ID = 0;
  static ::org::omg::PortableServer::IdAssignmentPolicyValue * USER_ID;
  static const jint _SYSTEM_ID = 1;
  static ::org::omg::PortableServer::IdAssignmentPolicyValue * SYSTEM_ID;
private:
  static JArray< ::org::omg::PortableServer::IdAssignmentPolicyValue * > * enume;
  static JArray< ::java::lang::String * > * state_names;
public:
  static ::java::lang::Class class$;
};

#endif // __org_omg_PortableServer_IdAssignmentPolicyValue__
