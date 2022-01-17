fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val S=br.readLine()
    val P=br.readLine()
    val f=Array(P.length){0}

    var j=0
    for(i in 1 until P.length){
        while(j>0 && P[i]!=P[j]) j=f[j-1]
        if(P[i]==P[j]) f[i]=++j
    }

    j=0
    for(i in S.indices){
       while(j>0 && P[j]!=S[i]) j=f[j-1]
        if(P[j]==S[i]) j++
        if(j==P.length){
            println(1)
            return
        }
    }
    println(0)
}