#include <iostream>
#include <sstream>
#include <string>
#include <node.h>

#include "leveldb/db.h"

using namespace v8;

Handle<Value> Put(const Arguments& args) {
  HandleScope scope;
  leveldb::DB* db;
  leveldb::Options *options=new leveldb:: Options();
  options->create_if_missing=true;
  
  leveldb::Status status=leveldb::DB::Open(*options,"/tmp/nodetest",&db);
  if(false==status.ok()){
  }
  leveldb::WriteOptions writeOptions;
  for(int i=0;i<256;i++){
    std::ostringstream keyStream;
    keyStream <<"Key"<<i;
    std:: ostringstream valueStream;
    valueStream <<"Test data value: "<<i;
    db->Put(writeOptions,keyStream.str(),valueStream.str());
  }
  return scope.Close(String::New("put successful"));
}

Handle<Value> CreateFunction(const Arguments& args) {
  HandleScope scope;
  Local<FunctionTemplate> tpl = FunctionTemplate::New(Put);
  Local<Function> fn = tpl->GetFunction();
  fn->SetName(String::NewSymbol("theFunction")); // omit this to make it anonymous

  return scope.Close(fn);
}

void InitAll(Handle<Object> exports, Handle<Object> module) {
  module->Set(String::NewSymbol("exports"),
      FunctionTemplate::New(CreateFunction)->GetFunction());
}

NODE_MODULE(put, InitAll)
