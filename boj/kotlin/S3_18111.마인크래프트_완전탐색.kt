import java.io.*

fun main(){
    val br =BufferedReader(InputStreamReader(System.`in`))
    val bw=BufferedWriter(OutputStreamWriter(System.out))

    val (N,M,B) = br.readLine().split(' ').map{it.toInt()}
    val heightArr = ArrayList<Int>().apply{
        repeat(N){ addAll(br.readLine().split(' ').map{it.toInt()}) }
        sort()
    }

    var p=0
    var insBlock=0
    var delBlock=heightArr.sumOf{it-heightArr.first()}

    var ans=Pair(delBlock * 2 + insBlock,heightArr.first(),)
    for(height in heightArr.first()+1..heightArr.last()){

        while(heightArr[p]<height){
            p++
        }
        insBlock+=p
        delBlock-=heightArr.lastIndex-p+1
        if(delBlock+B>=insBlock && ans.first>=insBlock+2*delBlock){
            ans=Pair(insBlock+2*delBlock,height)
        }
    }
    bw.write("${ans.first} ${ans.second}\n")
    bw.flush()
}