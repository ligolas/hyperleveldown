#include <node.h>
#include <nan.h>

#include "leveldbbinding.h"
#include "database.h"
#include "iterator.h"

using namespace v8;
namespace levelbinding{

NAN_METHOD(Destroy){
	char* location=NanFromV8String(args[0].As<v8::Object>(),Nan::UTF8,NULL,NULL,0,v8::String::NO_OPTIONS);
	leveldb::Options options;
	leveldb::Status status;
	status=leveldb::DestroyDB(location, options);
	 NanCallback* callback = new NanCallback(
      v8::Local<v8::Function>::Cast(args[1]));		
	if(status.ok()){
	 callback->Call(0, NULL);
	}
	else{
		v8::Local<v8::Value> argv[] = {
        v8::Exception::Error(v8::String::New("destory failed"))
    };
	 callback->Call(0, argv);
	}
	 NanReturnUndefined();
}
NAN_METHOD(Repair){
	char* location=NanFromV8String(args[0].As<v8::Object>(),Nan::UTF8,NULL,NULL,0,v8::String::NO_OPTIONS);
	leveldb::Options options;
	leveldb::Status status;
	status=leveldb::RepairDB(location, options);
	 NanCallback* callback = new NanCallback(
      v8::Local<v8::Function>::Cast(args[1]));		
	if(status.ok()){
	 callback->Call(0, NULL);
	}
	else{
		v8::Local<v8::Value> argv[] = {
        v8::Exception::Error(v8::String::New("Repair failed"))
    };
	 callback->Call(0, argv);
	}
	 NanReturnUndefined();
}
void Init(Handle<Object> target){
	Database::Init();

  v8::Local<v8::Function> leveldbbinding =
      v8::FunctionTemplate::New(LevelDBBinding)->GetFunction();
	 leveldbbinding->Set(
      NanSymbol("destroy")
    , v8::FunctionTemplate::New(Destroy)->GetFunction()
  );

  leveldbbinding->Set(
      NanSymbol("repair")
    , v8::FunctionTemplate::New(Repair)->GetFunction()
  );
	levelbinding::Iterator::Init();
	target->Set(NanSymbol("leveldbbinding"),leveldbbinding);

}

NODE_MODULE(leveldbbinding, Init)
}//namespace leveldbbinding