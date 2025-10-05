#Music playlist Simulation
#to solve playlist related features such as add,delete and play songs(in order)
#practical application of singly linked list

#creating node
class Node:
    def __init__(self, song):
        self.song = song
        self.next = None

#creating playlist
class Playlist:
    def __init__(self):
        self.head = None

# adding songs
    def add_song(self, song):
        new_node = Node(song)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

#deleting songs
    def delete_song(self, song):
        temp = self.head
        if temp and temp.song == song:
            self.head = temp.next
            return
        prev = None
        while temp and temp.song != song:
            prev = temp
            temp = temp.next
        if temp is None:
            print("Song", song, "not found in playlist!")
            return
        prev.next = temp.next

#playing songs
    def play(self):
        temp = self.head
        if not temp:
            print("Playlist is empty.")
            return
        while temp:
            print("Playing:", temp.song)
            temp = temp.next

#use for sample testing
'''playlist = Playlist()
playlist.add_song("A")
playlist.add_song("B")
playlist.add_song("C")
playlist.add_song("D")

print("Initial playlist:")
playlist.play()

print("Deleting:")
playlist.delete_song("B")

print("Updated Playlist:")
playlist.play()'''
