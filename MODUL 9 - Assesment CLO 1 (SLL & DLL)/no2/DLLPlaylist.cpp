#include "DLLPLaylist.h"
#include <iostream>
using namespace std;

bool isEmpty(List List) {
    return (List.head == Nil && List.tail == Nil);
}

void createList(List &List) {
    List.head = Nil;
    List.tail = Nil;
}

address allocate(string Title, string Artist, int DurationSec, int PlayCount, float Rating) {
    address P = new Node;
    P->info.Title = Title;
    P->info.Artist = Artist;
    P->info.DurationSec = DurationSec;
    P->info.PlayCount = PlayCount;
    P->info.Rating = Rating;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void deallocate(address &P) {
    delete P;
}

void insertFirst(List &List, address P) {
    if (isEmpty(List)) {
        List.head = P;
        List.tail = P;
    } else {
        P->next = List.head;
        List.head->prev = P;
        List.head = P;
    }
}

void insertLast(List &List, address P) {
    if (isEmpty(List)) {
        List.head = P;
        List.tail = P;
    } else {
        P->prev = List.tail;
        List.tail->next = P;
        List.tail = P;
    }
}

void insertAfter(List &List, address P, address Q) {
    if (Q != Nil) {
        P->next = Q->next;
        P->prev = Q;
        if (Q->next != Nil) {
            Q->next->prev = P;
        } else {
            List.tail = P;
        }
        Q->next = P;
    }
}

void insertBefore(List &List, address P, address Q) {
    if (Q != Nil) {
        P->prev = Q->prev;
        P->next = Q;
        if (Q->prev != Nil) {
            Q->prev->next = P;
        } else {
            List.head = P;
        }
        Q->prev = P;
    }
}

void deleteFirst(List &List) {
    if (!isEmpty(List)) {
        address P = List.head;
        if (List.head == List.tail) {
            List.head = Nil;
            List.tail = Nil;
        } else {
            List.head = List.head->next;
            List.head->prev = Nil;
        }
        deallocate(P);
    }
}

void deleteLast(List &List) {
    if (!isEmpty(List)) {
        address P = List.tail;
        if (List.head == List.tail) {
            List.head = Nil;
            List.tail = Nil;
        } else {
            List.tail = List.tail->prev;
            List.tail->next = Nil;
        }
        deallocate(P);
    }
}

void deleteAfter(List &List, address P, address &Q) {
    if (P != Nil && P->next != Nil) {
        Q = P->next;
        P->next = Q->next;
        if (Q->next != Nil) {
            Q->next->prev = P;
        } else {
            List.tail = P;
        }
        deallocate(Q);
    }
}

void deleteBefore(List &List, address P, address &Q) {
    if (P != Nil && P->prev != Nil) {
        Q = P->prev;
        P->prev = Q->prev;
        if (Q->prev != Nil) {
            Q->prev->next = P;
        } else {
            List.head = P;
        }
        deallocate(Q);
    }
}

void updateAtPosition(List &List, int posisi) {
    if (!isEmpty(List)) {
        address P = List.head;
        int idx = 1;
        while (P != Nil && idx < posisi) {
            P = P->next;
            idx++;
        }
        if (P != Nil) {
            cout << "Update song posisi- " << posisi << ":\n";
            cout << "Title: ";
            cin >> P->info.Title;
            cout << "Artist: ";
            cin >> P->info.Artist;
            cout << "Duration (sec): ";
            cin >> P->info.DurationSec;
            cout << "PlayCount: ";
            cin >> P->info.PlayCount;
            cout << "Rating (0.0 - 5.0): ";
            cin >> P->info.Rating;
            cout << "Song berhasil diupdate!" << endl;
        } else {
            cout << "Posisi tidak valid!" << endl;
        }
    }
}

void updateBefore(List &List, address P) {
    if (P != Nil && P->prev != Nil) {
        address Q = P->prev;
        cout << "Update song sebelum " << P->info.Title << ":\n";
        cout << "Title: ";
        cin >> Q->info.Title;
        cout << "Artist: ";
        cin >> Q->info.Artist;
        cout << "Duration (sec): ";
        cin >> Q->info.DurationSec;
        cout << "PlayCount: ";
        cin >> Q->info.PlayCount;
        cout << "Rating (0.0 - 5.0): ";
        cin >> Q->info.Rating;
        cout << "Song berhasil diupdate!" << endl;
    } else {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
}

void viewList(List List) {
    if (isEmpty(List)) {
        cout << "Playlist kosong!" << endl;
    } else {
        address P = List.head;
        int idx = 1;
        cout << "Playlist :" << endl;
        while (P != Nil) {
            cout << "Posisi ke-" << idx << endl;
            cout << "Title: " << P->info.Title << endl;
            cout << "Artist: " << P->info.Artist << endl;
            cout << "Duration (sec): " << P->info.DurationSec << endl;
            cout << "PlayCount: " << P->info.PlayCount << endl;
            cout << "Rating: " << P->info.Rating << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            P = P->next;
            idx++;
        }
    }
}

void searchByPopularityRange(List List, float minScore, float maxScore) {
    if (isEmpty(List)) {
        cout << "Playlist kosong!" << endl;
    } else {
        address P = List.head;
        int idx = 1;
        bool found = false;
        cout << "Songs Dengan Popularity Score " << minScore << " - " << maxScore << " :" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (P != Nil) {
            float popularityScore = 0.8f * P->info.PlayCount + 20.0f * P->info.Rating;
            if (popularityScore >= minScore && popularityScore <= maxScore) {
                cout << "Posisi ke-" << idx << endl;
                cout << "Title: " << P->info.Title << endl;
                cout << "Artist: " << P->info.Artist << endl;
                cout << "Popularity Score: " << popularityScore << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                found = true;
            }
            P = P->next;
            idx++;
        }
        if (!found) {
            cout << "Tidak ada song dalam range popularity score tersebut" << endl;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}
