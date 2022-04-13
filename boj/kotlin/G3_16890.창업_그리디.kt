fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val koo = br.readLine().toMutableList().apply{sort()}
    val cube = br.readLine().toMutableList().apply{sort()}

    var kl = 0
    var kr = koo.lastIndex/2
    var cl = cube.size/2 + cube.size%2
    var cr= cube.lastIndex

    var ans = Array(koo.size){' '}
    var al = 0
    var ar = ans.lastIndex
    for(i in 0 until koo.size){
        if(i%2==0){
            if(koo[kl]>=cube[cr]){
                ans[ar]= koo[kr]
                ar--
                kr--
            }else{
                ans[al]=koo[kl]
                al++
                kl++
            }
        }else {
            if(koo[kl]>=cube[cr]){
                ans[ar] = cube[cl]
                ar--
                cl++
            }else{
                ans[al]=cube[cr]
                al++
                cr--
            }
        }
    }
    println(ans.joinToString(""){"$it"})
}