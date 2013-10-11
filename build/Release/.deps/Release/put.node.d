cmd_Release/put.node := ln -f "Release/obj.target/put.node" "Release/put.node" 2>/dev/null || (rm -rf "Release/put.node" && cp -af "Release/obj.target/put.node" "Release/put.node")
