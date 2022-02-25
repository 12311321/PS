fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val n=arrayOf(6,2,5,5,4,5,6,3,7,6)
    val dp=Array(2){Array(101){""} }

    fun comp(s1:String, s2:String):Boolean{
        if(s1.length==s2.length){
            for(i in s1.indices){
                if(s1[i]!=s2[i]) return s1[i]>s2[i]
            }
        }
        return s1.length>s2.length
    }
    for(i in 0..100) for(j in 0 until 10){
        if(i!=0 && dp[0][i].isEmpty()) continue
        if(i+n[j]>100) continue
        val minNum=StringBuilder(dp[0][i]).append(j.toString()).toString()
        val maxNum=StringBuilder(dp[1][i]).append(j.toString()).toString()

        if(minNum[0]!='0') {
            if (dp[0][i + n[j]] == "") dp[0][i + n[j]] = minNum
            else if (comp(dp[0][i + n[j]], minNum)) dp[0][i + n[j]] = minNum
        }
        if(maxNum[0]!='0') {
            if (dp[1][i + n[j]] == "") dp[1][i + n[j]] = maxNum
            else if (!comp(dp[1][i + n[j]], maxNum)) dp[1][i + n[j]] = maxNum
        }
    }

    repeat(br.readLine().toInt()){
        br.readLine().toInt().let{ bw.write("${dp[0][it]} ${dp[1][it]}\n") }
    }
    bw.close()
}