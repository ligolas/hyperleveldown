var leveldown=require('./build/Release/leveldbbinding')
var db=leveldown.leveldbbinding('/tmp/testdb')
function test (db, method, callback) {
    var startTime = Date.now();
    var total = 1000000;
    var success = 0;
    var fail = 0;
    var ops = [
        { type: 'del', key: 'father' }
      , { type: 'put', key: 'name', value: 'Yuri Irsenovich Kim' }
      , { type: 'put', key: 'dob', value: '16 February 1941' }
      , { type: 'put', key: 'spouse', value: 'Kim Young-sook' }
      , { type: 'put', key: 'occupation', value: 'Clown' }
    ]
    var batchdone=function(error){
        if(error)
            return console.log(error)
        else
            return console.log('batch seems work fine')
    }
    var done = function(error, value){
        if(error) fail++;
        else success++
        if(fail + success == total){
            console.log(Date.now() - startTime,success,fail)
            callback&&callback();
        }
    };
    var iter=db.iterator()
    var iteratorcb=function(error,key,value){
        if(!error){
            if(key!='hello99992'){
                console.log('key: '+key+' value: '+value)
                iter.next(iteratorcb)
            }
        }
        else
            console.log(error)
    }

    switch(method){
        case 'get':
            for(var i=0;i<total;i++){
            db[method]('hello'+i,done);
        }
        break;
        case 'put':
            for(var i=0;i<total;i++){
            db[method]('hello'+i,i,done);
        }
        break;
        case 'iterator':
            iter.next(iteratorcb);
        break;
        case 'batch':
            db[method](ops,batchdone);
        break;

    }
}
db.open(function(error){
    if(error) 
        throw 'db error';
    test(db, 'batch'); 
})



