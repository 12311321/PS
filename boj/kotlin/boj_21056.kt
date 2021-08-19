import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br= BufferedReader(InputStreamReader(System.`in`))
val bw= BufferedWriter(OutputStreamWriter(System.out))

data class Num(var a:Long, var b:Long)
data class Tap(var t:Long, var a:Long, var b:Long)
fun Num.isGreaterThanOrEqual(n:Num):Boolean{
    return this.a*n.b>=n.a*this.b
}
fun main(){
   val k=br.readLine().toInt()
    val taps=Array(k){Tap(0,0,0)}
    val temp=Num(0,0)
    for(i in 0..k-1){
       val str=br.readLine().split(' ')
        taps[i].t=str[0].toLong()
        taps[i].a=str[1].toLong()
        taps[i].b=str[2].toLong()
       temp.a+=taps[i].t*taps[i].a
        temp.b+=taps[i].a
    }
    taps.sortWith{a:Tap,b:Tap->when{
        a.t>b.t->1
        a.t<b.t->-1
        else->0
    }}
    val r=br.readLine().toInt()
    for(i in 0..r-1){
        val (t,p)=br.readLine().split(' ').map{it.toLong()}
        val minTemp=Num(temp.a,temp.b)
        if(minTemp.b>p){
            bw.write("no\n")
            continue
        }
        for(j in 0..k-1){
            if(minTemp.b+taps[j].b-taps[j].a>=p){

                minTemp.a+=taps[j].t*(p-minTemp.b)
                minTemp.b=p
                break
            }else{

                minTemp.a+=taps[j].t*(taps[j].b-taps[j].a)
                minTemp.b+=taps[j].b-taps[j].a
            }
        }
        if(minTemp.b<p){
            bw.write("no\n")
            continue
        }

        val maxTemp=Num(temp.a,temp.b)
        for(j in k-1 downTo(0)){
            if(maxTemp.b+taps[j].b-taps[j].a>=p){

                maxTemp.a+=taps[j].t*(p-maxTemp.b)
                maxTemp.b=p
                break
            }else{

                maxTemp.a+=taps[j].t*(taps[j].b-taps[j].a)
                maxTemp.b+=taps[j].b-taps[j].a
            }
        }
        if(Num(t,1).isGreaterThanOrEqual(minTemp) && maxTemp.isGreaterThanOrEqual(Num(t,1))){
            bw.write("yes\n")
        }else{
            bw.write("no\n")
        }


    }
    bw.flush()


}