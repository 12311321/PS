fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val (W,H,A) = br.readLine().split(' ').map{it.toInt()}

    fun getCount(a:Int, b:Int):Int{
        var l = a
        var cnt=0
        while(l>b){
            cnt++
            l = l/2+l%2
        }
        return cnt
    }
    var ans=-1
    for(width in 1..A){
        if(A%width!=0) continue
        val height = A/width
        if(W<width || H<height) continue
        val cnt= getCount(W,width) + getCount(H,height)
        ans = if(ans==-1) cnt else ans.coerceAtMost(cnt)
    }
    println(ans)
}