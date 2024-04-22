//Assig 7(FIFO,LRU,Optimal)
#include <iostream>
#include <climits>
using namespace std;
void printFrames(int frame[], int capacity)
{
    cout << "Frame Structure: ";
    for (int i = 0; i < capacity; i++)
    {
        if (frame[i] == -1)
        {
            cout << "[ ]";
        }
        else
        {
            cout << "[" << frame[i] << "]";
        }
    }
    cout << endl;
}
void fifo(int pages[], int n, int capacity)
{
    int pageFaults = 0;
    int frame[capacity];
    int frameIndex = 0;
    for (int i = 0; i < capacity; i++)
    {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        bool pageExists = false;
        for (int j = 0; j < capacity; j++)
        {
            if (frame[j] == pages[i])
            {
                pageExists = true;
                break;
            }
        }
        if (!pageExists)
        {
            frame[frameIndex] = pages[i];
            frameIndex = (frameIndex + 1) % capacity;
            pageFaults++;
        }
        printFrames(frame, capacity);
    }
    cout << "FIFO Page Replacement Algorithm\n";
    cout << "Number of Page Faults: " << pageFaults << endl;
}
void lru(int pages[], int n, int capacity)
{
    int pageFaults = 0;
    int frame[capacity];
    int counter[capacity] = {0};
    for (int i = 0; i < capacity; i++)
    {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        bool pageExists = false;
        int idx = 0; // Index of the least recently used page
        // Check if the page is already in a frame
        for (int j = 0; j < capacity; j++)
        {
            if (frame[j] == pages[i])
            {
                pageExists = true;
                break;
            }
            if (counter[j] < counter[idx])
            {
                idx = j; // Update the index of the least recently used page
            }
        }
        // If page is not in a frame, and there's an empty frame available, fill it
        if (!pageExists)
        {
            for (int j = 0; j < capacity; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = pages[i];
                    pageFaults++;
                    pageExists = true;
                    counter[j] = i;
                    break;
                }
            }
        }
        // If page is not in a frame and all frames are full, proceed with LRU replacement
        if (!pageExists)
        {
            frame[idx] = pages[i];
            pageFaults++;
        }
        // Update the counter for the accessed page
        for (int j = 0; j < capacity; j++)
        {
            if (frame[j] == pages[i])
            {
                counter[j] = i;
                break;
            }
        }
        printFrames(frame, capacity);
    }
    cout << "\nLRU Page Replacement Algorithm\n";
    cout << "Number of Page Faults: " << pageFaults << endl;
}
void optimal(int pages[], int n, int capacity)
{
    int pageFaults = 0;
    int frame[capacity];
    int nextOccurrence[capacity];
    for (int i = 0; i < capacity; i++)
    {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        bool pageExists = false;
        for (int j = 0; j < capacity; j++)
        {
            if (frame[j] == pages[i])
            {
                pageExists = true;
                break;
            }
        }
        if (!pageExists)
        {
            int idx = 0;      // Index of the page to be replaced
            int farthest = 0; // Distance to the next occurrence of the page to be replaced
            for (int j = 0; j < capacity; j++)
            {
                int k;
                for (k = i + 1; k < n; k++)
                {
                    if (pages[k] == frame[j])
                    {
                        break;
                    }
                }
                if (k == n)
                {
                    idx = j; // If the page won't occur again, it's the best candidate for replacement
                    break;
                }
                if (k > farthest)
                {
                    farthest = k; // Update farthest to the next occurrence of the page
                    idx = j;      // Update the index of the page to be replaced
                }
            }
            frame[idx] = pages[i]; // Replace the page
            pageFaults++;
        }
        printFrames(frame, capacity);
    }
    cout << "\nOptimal Page Replacement Algorithm\n";
    cout << "Number of Page Faults: " << pageFaults << endl;
}
int main()
{
    int capacity, n, choice;
    cout << "Enter the number of frames: ";
    cin >> capacity;
    cout << "Enter the number of pages: ";
    cin >> n;
    int pages[n];
    cout << "Enter the reference string: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    cout << "Select Page Replacement Algorithm:\n";
    cout << "1. FIFO\n";
    cout << "2. LRU\n";
    cout << "3. Optimal\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        fifo(pages, n, capacity);
        break;
    case 2:
        lru(pages, n, capacity);
        break;
    case 3:
        optimal(pages, n, capacity);
        break;
    default:
        cout << "Invalid choice\n";
    }
    return 0;
}