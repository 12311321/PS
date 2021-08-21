package boj_18319

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*

val br = BufferedReader(InputStreamReader(System.`in`))
val bw= BufferedWriter(OutputStreamWriter(System.out))

fun main(){
    val (N,K)=br.readLine().split(' ').map{it.toInt()}
    val B=br.readLine().split(' ').map{it.toInt()}.toIntArray()
    B.sortedWith{a:Int,b:Int->when{
        a<b->1
        a>b->-1
        else->0
    } }

    var ans=0
    for(i in 1..1000){
        ans=max(ans,search(i,B,N,K))
    }
    bw.write(ans.toString()+"\n")
    bw.flush()
}
fun search(k:Int,B:IntArray,N:Int,K:Int):Int{

    val maxHeap= PriorityQueue<Int>{a:Int,b:Int->when{
        a<b->1
        a>b->-1
        else->0
    }}
    for(i in 0..N-1){
        maxHeap.add(B[i])
    }
    var basketnum=0
    var berrynum=0
    while(maxHeap.isNotEmpty()){
        if(basketnum==K){
            break
        }
        var temp=maxHeap.poll()
        when{
            basketnum>=K/2->{
                val bn=min(K-basketnum,temp/k)
                when(bn){
                    0->{
                        basketnum++
                        berrynum+=temp
                    }else->{
                      basketnum+=bn
                      temp-=bn*k
                    berrynum+=k*bn
                      maxHeap.add(temp)
                    }
                }

            }else->{
                val bn=min(K/2-basketnum,temp/k)
            when(bn){
                0->{
                    basketnum++
                }else->{
                  basketnum+=bn
                  temp-=bn*k
                  maxHeap.add(temp)
                }
            }

            }
        }
    }




    return berrynum
}