# Also known as Pub-Sub design pattern

from abc import ABC, abstractmethod

# Syntax
def observer_syntax():

    # Step 1: The Subject
    class Subject(ABC):
        def __init__(self):
            self._observers = set()      # can be a list

        def attach(self, observer):
            self._observers.add(observer)

        def detach(self, observer):
            self._observers.remove(observer)

        def notify_observers(self):
            for observer in self._observers:
                observer.update()

    # Step 2: The Observer Interface
    class Observer:
        @abstractmethod
        def update(self):
            pass

    # Step 3: Concrete Observer
    class ConcreteObserver(Observer):
        def __init__(self, name):
            self.name = name

        def update(self):
            print(f"{self.name} has been notified.")


    subject = Subject()
    obs1 = ConcreteObserver("Observer1")
    obs2 = ConcreteObserver("Observer2")
    obs3 = ConcreteObserver("Observer3")

    subject.attach(obs1)
    subject.attach(obs2)
    subject.attach(obs3)

    subject.notify_observers()


# Chat application example
def observer_example():

    class ChatRoom:
        def __init__(self):
            self._participants = set()

        def join(self, participant):
            self._participants.add(participant)

        def leave(self, participant):
            self._participants.remove(participant)

        def broadcast(self, message):
            for participant in self._participants:
                participant.receive(message)

    class Participant(ABC):
        @abstractmethod
        def receive(self, message):
            pass

    class ChatMember(Participant):
        def __init__(self, name):
            self.name = name

        def receive(self, message):
            print(f"{self.name} received message - {message}")


    chat_room1 = ChatRoom()
    user1 = ChatMember("User1")
    user2 = ChatMember("User2")
    user3 = ChatMember("User3")

    chat_room1.join(user1)
    chat_room1.join(user2)
    chat_room1.join(user3)

    chat_room1.broadcast("Welcome to the chat App.")

if __name__ == "__main__":
    observer_syntax()
    observer_example()