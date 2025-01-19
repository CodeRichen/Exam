class Node {
    constructor(val) {
        this.val = val
        this.next = null
        this.prev = null
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null
        this.tail = null
        this.length = 0
    }

    push(val) {
        var newNode = new Node(val)
        if(this.length === 0) {
            this.head = newNode
            this.tail = newNode
        } else {
            this.tail.next = newNode
            newNode.prev = this.tail
            this.tail = newNode
        }
        this.length++
        return this
    }

    pop() {
        if(!this.head) return undefined
        var poppedNode = this.tail

        if(this.length === 1) {
            this.head = null
            this.tail = null
        } else {
            this.tail = poppedNode.prev
            this.tail.next = null
            poppedNode.prev = null
        }
        this.length--
        return poppedNode
    }

    shift() {
        if(this.length === 0) return undefined
        var shiftedNode = this.head

        if(this.length === 1) {
            this.head = null
            this.tail = null
        } else {
            this.head = shiftedNode.next
            this.head.prev = null
            shiftedNode.next = null
        }
        this.length--
        return shiftedNode
    }

    unshift(val) {
        var newNode = new Node(val)
        if(this.length === 0) {
            this.head = newNode
            this.tail = newNode
        } else {
            this.head.prev = newNode
            newNode.next = this.head
            this.head = newNode
        }
        this.length++
        return this
    }

    get(index) {
        if(index < 0 || index >= this.length) return undefined

        var count, current
        if(index <= this.length / 2) {
            while (count !== index) {
                count = 0
                current = this.head
                current = current.next
                count++
            }
        } else {
            while (count !== index) {
                count = this.length - 1
                current = this.tail
                current = current.prev
                count--
            }
        }
        return current
    }

    set(index, val) {
        var foundNode = this.get(index)
        if(foundNode !== undefined) {
            foundNode.val = val
            return true
        }
        return false
    }

    insert(index, val) {
        if(index < 0 || index > this.length) return false
        if(index === 0) return this.unshift(val)
        if(index === this.length) return this.push(val)
        
        var newNode = new Node(val)
        var beforeNode = this.get(index - 1)
        var afterNode = beforeNode.next
        
        beforeNode.next = newNode
        newNode.prev = beforeNode

        newNode.next = afterNode
        afterNode.prev = newNode

        this.length++
        return true
    }

    remove(index) {
        if(index < 0 || index >= this.length) return false
        if(index === 0) return this.shift()
        if(index === this.length - 1) return this.pop()

        var removedNode = this.get(index)
        removedNode.prev.next = removedNode.next
        removedNode.next.prev = removedNode.prev

        removedNode.next = null
        removedNode.prev = null

        this.length--
        return removedNode
    }
}