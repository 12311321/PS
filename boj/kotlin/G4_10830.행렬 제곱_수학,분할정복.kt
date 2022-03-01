fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    var (N,B) = br.readLine().split(' ').map{it.toLong()}
    var matrix=Array(N.toInt()){br.readLine().split(' ').map{it.toInt()}.toTypedArray()}

    fun mul(n:Int,a:Array<Array<Int>>, b:Array<Array<Int>>):Array<Array<Int>>{
        val ret=Array(n){Array(n){0} }
        for(r in 0 until n) for(c in 0 until n) for(k in 0 until n){
            ret[r][c]=(ret[r][c]+a[r][k]*b[k][c])%1000
        }
        return ret
    }

    var A=Array(N.toInt()){r->Array(N.toInt()){c->if(r==c)1 else 0} }
    while(B>0){
        if(B%2==1L){
            A=mul(N.toInt(),A,matrix)
        }
        matrix=mul(N.toInt(),matrix,matrix)
        B/=2
    }
    bw.write(A.joinToString("\n"){it.joinToString(" ")})
    bw.close()
}