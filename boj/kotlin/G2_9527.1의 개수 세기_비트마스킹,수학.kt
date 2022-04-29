fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val calNumOfOne = {k:Long->
        val nk=k+1
        var t=2L
        var num=0L
        while(t/2<=nk){
            num+=nk/t*(t/2)+maxOf(0,(nk%t)-(t/2))
            t *=2
        }
        num
    }

    br.readLine().split(' ').map{it.toLong()}.run{
        println(calNumOfOne(get(1))-calNumOfOne(get(0)-1))
    }
}