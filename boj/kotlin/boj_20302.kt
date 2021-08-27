import java.io.*
import kotlin.math.*
import java.util.*
val isPrime=Array<Boolean>(100001){true}
val primeList=ArrayList<Int>()
fun initPrime(){
    for(i in 2..100000){
        if(isPrime[i]){
            primeList.add(i)
            for(j in i*2..100000 step i){
                isPrime[j]=false
            }
        }
    }
}
fun pushPrime(data:Int, target:Array<Int>, p:Int){
    var k=abs(data)
   for(i in primeList){
       if(isPrime[k] || k==1){
           target[k]+=p
           return
       }
       while(k%i==0){
           target[i]+=p
           k/=i
       }
   }

}
fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    initPrime()
    val N=br.readLine().toInt()
    val st=StringTokenizer(br.readLine())
    val numArr=Array<Int>(100001){0}
    var nextnum=st.nextToken().toInt()
    if(nextnum==0){
        println("mint chocolate")
        return
    }
    pushPrime(nextnum,numArr,1)
    while(st.hasMoreTokens()){
        val op:String=st.nextToken()
        nextnum=st.nextToken().toInt()
        if(op=="*"){
            if(nextnum==0){
                println("mint chocolate")
                return
            }
            pushPrime(nextnum,numArr,1)

        }else{
            pushPrime(nextnum.toInt(),numArr,-1)
        }
    }
    var ans="mint chocolate"
    for(i in primeList){
        if(numArr[i]<0){
            ans="toothpaste"
            break
        }
    }
    println(ans)
}
