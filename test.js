var leveldown=require('./build/Release/leveldbbinding')
var db=leveldown.leveldbbinding('/tmp/testdb')
//console.log(db)
db.open(function(error){
    if(!error){
        var putcb=function(error){
            if(!error)
                console.log('put success')
            else
                console.log(error)
        }
        var getcb=function(error,value){
            if(!error)
                console.log(value)
            else
                console.log(error)
        }
        var approximateSizecb=function(error,size){
            if(!error){
                console.log(size)
            }   
        }
        //single put test
        // db.put('teest','bonjur',putcb)

        //get test
        // db.get('hello900000',{asBuffer:false},getcb)

        //get proterty test
        //console.log(db.getProperty('leveldb.stats'))
        
        //approximateSize test
        db.approximateSize('hello0','hello900',approximateSizecb)
    
 //    var startTime = Date.now();
 //    var total = 10000000;
 //    var success = 0;
 //    var fail = 0;
 //    var done = function(error){
	// if(error) fail++;
	// else success++
	// if(fail + success == total){
	//     console.log(Date.now() - startTime,success,fail)
	// } 
 //    };

 //    for(var i=0;i<total;i++){
	// db.put('hello'+i,'world',done)
 //    }
}   
})



