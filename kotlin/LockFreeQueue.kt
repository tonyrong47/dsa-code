import kotlinx.coroutines.*
import kotlinx.coroutines.channels.Channel
import kotlin.system.measureTimeMillis

class LockFreeQueue<T>(capacity: Int) {
    private val channel = Channel<T>(capacity)

    suspend fun enqueue(value: T) {
        channel.send(value)
    }

    suspend fun dequeue(): T {
        return channel.receive()
    }

    fun close() {
        channel.close()
    }
}

fun main() = runBlocking {
    val queue = LockFreeQueue<Int>(100)

    val producer = launch(Dispatchers.Default) {
        for (i in 0 until 1000) {
            queue.enqueue(i)
            println("Produced: $i")
            delay(5) // simulate work
        }
        queue.close()
    }

    val consumer = launch(Dispatchers.Default) {
        for (item in queue.channel) {
            println("Consumed: $item")
            delay(10) // simulate work
        }
    }

    val time = measureTimeMillis {
        producer.join()
        consumer.join()
    }

    println("Processing finished in $time ms")
}
