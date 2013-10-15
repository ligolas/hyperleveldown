{
  "targets": [
    {
      "target_name": "leveldbbinding",
      "sources": [ "src/leveldbbinding.cc" 
      			  ,"src/database.cc"
      ],
      "dependencies": [
            "<(module_root_dir)/deps/leveldb/leveldb.gyp:leveldb"
        ]
     
     , "include_dirs"  : [
            "<!(node -p -e \"require('path').relative('.', require('path').dirname(require.resolve('nan')))\")"
        ]
    }
  ]
}
