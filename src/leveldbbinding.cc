#include "leveldbbinding.h"
#include "database.h"

#include <node.h>
#include <nan.h>

using namespace v8;
namespace leveldbbinding{


void Init(Handle<Object> target){
	Database::Init();
	target->Set(NanSymbol("leveldbbinding"),FunctionTemplate::New(LevelDBBinding)->GetFunction());
}

NODE_MODULE(leveldbbinding, Init)
}//namespace leveldbbinding