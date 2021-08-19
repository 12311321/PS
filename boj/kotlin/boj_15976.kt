package boj_15976

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br= BufferedReader(InputStreamReader(System.`in`))
val bw= BufferedWriter(OutputStreamWriter(System.out))
val INF=1E9.toInt()*2+1
fun main(){
    val xarr=ArrayList<Pair<Int,Long>>()
    val yarr=ArrayList<Pair<Int,Long>>()
    val N=br.readLine().toInt()
    for(i in 0..N-1){
        val (idx,x)=br.readLine().split(' ').map{it.toInt()}
        xarr.add(Pair(idx,x.toLong()))

    }
    val M=br.readLine().toInt()
    yarr.add(Pair(-INF,0L))
    for(i in 0..M-1){
        val (idx,y)=br.readLine().split(' ').map{it.toInt()}
        yarr.add(Pair(idx,y.toLong()))
    }
    yarr.add(Pair(INF,0L))
    val a=br.readLine().toInt()
    val b=br.readLine().toInt()

    var s=0
    var e=0
    var ac=0L
    var ans=0L
    for(i in 0..N-1){
        while(yarr[e].first<=xarr[i].first+b){
            ac+=yarr[e].second
            e++
        }
        while(yarr[s].first<xarr[i].first+a){
            ac-=yarr[s].second
            s++
        }
        ans+=ac*xarr[i].second
    }
    bw.write(ans.toString()+"\n")
    bw.flush()

}
