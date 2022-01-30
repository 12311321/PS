fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    var open=0
    var ans=0
    var tc=1
    var str=br.readLine()
    while(str[0]!='-'){
        str.forEach{
            if(it=='{') open++
            else{
                ans+=if(open==0) 1 else 0
                open+= if(open==0) 1 else -1
            }
        }
        bw.write("$tc. ${ans+open/2}\n")
        open=0
        ans=0
        tc++
        str=br.readLine()
    }
    bw.close()
}