import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.*
import java.util.*
fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    var str=br.readLine().split(' ')
    val N=str[0].toInt()
    val M=str[1].toInt()
    str=br.readLine().split(' ')
    val arr=Array<Int>(N){-1}

    for(i in 0..N-1){
        arr[i]=str[i].toInt()

    }
    var s=0; var e= arr.maxOrNull(); var ans=e
    while(s<= e!!){
        val m=(s+e)/2
        when(isPossible(m,arr,M)){
            true->{
                ans=m
                e=m-1
            }
            else->{
                s=m+1
            }
        }
    }
    bw.write(ans!!.toString()+"\n")
    bw.flush()
}
fun isPossible(n:Int, arr:Array<Int>, M:Int):Boolean{
    var num=1; var minval=arr[0]; var maxval=arr[0]
    for(i in 1..arr.size-1){
        minval=min(minval,arr[i])
        maxval=max(maxval,arr[i])
        if(maxval-minval>n){
            num++
            minval=arr[i]
            maxval=arr[i]
        }
    }

    return num<=M
}
