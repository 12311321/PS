fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    br.readLine().toLong().let{n->
        var k=1L
        while(k<n)k*=2
        bw.write(if(k==n)"TAK" else "NIE")
    }
    bw.close()
}