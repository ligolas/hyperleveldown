{
  "targets": [
    {
      "target_name": "put",
      "sources": [ "put.cpp" ],
      "dependencies": [
            "<(module_root_dir)/deps/leveldb/leveldb.gyp:leveldb"
        ]
     
    }
  ]
}
