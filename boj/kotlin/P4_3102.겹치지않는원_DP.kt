fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val circle=Array(301){Array(301){0} }
    val dp=Array(301){Array(301){0} }
    val N=br.readLine().toInt()
    repeat(N){
        br.readLine().split(' ').map{it.toInt()}.run{
            circle[100+get(0)-get(1)][100+get(0)+get(1)]=1
        }
    }

    for(size in 2..300){
        for(l in 0..300-size){
            //l..l+size
            for(m in l..l+size){
                //l..m ~ m..l+size
                dp[l][l+size]=dp[l][l+size].coerceAtLeast(dp[l][m]+dp[m][l+size])
            }
            dp[l][l+size]+=circle[l][l+size]
        }
    }

    bw.write("${N-dp[0][300]}\n")
    bw.close()
}