#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
// Custom comparator to compare elements based on frequency and order
struct Compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        // If frequencies are different, sort by frequency
        if (a.second != b.second)
        {
            return a.second > b.second; // Greater frequency first
        }
        else
        {
            return a.first < b.first; // Preserve the order for same frequency
        }
    }
};
// Short function start-->>
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
}
void printVector(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void printVectorString(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << endl;
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << endl;
    }
}
void printVectorVectorString(vector<vector<string>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << endl;
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}
void printStack(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Short function end-->>
/*
1)A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally, Heaps can be of two types:

Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.

Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree. .
Li'll Interoduction----->>>
1️⃣ How to define its Heaps?
-->> It will given K and ask for smallest or largest.
2️⃣ Which heaps to choose and when?
---->> K + smallest => Max Heap || K + largest => Min Heap
3️⃣  Min Heap define---->>
 priority_queue<int,vector<int>,gretaer<int>>min;
4️⃣  Max Heap define---->>
priority_queue<int>max;
5️⃣ pair of pair define---->>
pair<int,pair<int,int>>ppi;


*/
// ==============================ADITYA VERMA PLAYLIST=====================================>>
/*
1. K-th smallest element
ANS : Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.
Input : arr[] = {7, 10, 4, 3, 20, 15}; k = 3  || Output : 7
*/
// Bruteforce ----------->
// TC : O(NlogN)
// SC :
int kthSmallestElementBruteforce(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(NlogK)
// SC :
int kthSmallestElementOptimal(vector<int> &arr, int k)
{
    priority_queue<int> maxH;
    for (auto it : arr)
    {
        maxH.push(it);
        if (maxH.size() > k)
            maxH.pop();
    }
    return maxH.top();
}
// Optimal 2 ------------->>
// TC: O(n)
// SC:O(1)
int partition(vector<int> &arr, int l, int r)
{
    int f = arr[r];
    int i = l;

    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= f)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kth_Smallest_Element(vector<int> &arr, int l, int r, int k)
{
    if (k <= r - l + 1 && k > 0)
    {

        int ind = partition(arr, l, r);

        if (ind - l == k - 1)
        {
            return arr[ind];
        }
        if (ind - l > k - 1)
        {
            return kth_Smallest_Element(arr, l, ind - 1, k);
        }

        return kth_Smallest_Element(arr, ind + 1, r, k - ind + l - 1);
    }
    return INT_MAX;
}
/*
2.  K largest elements in an array
ANS : write an efficient program for printing k largest elements in an array. Elements in array can be in any order.
Input :  arr= [1, 23, 12, 9, 30, 2, 50] ,k=3 || Output :50,30,23
*/
// Bruteforce ----------->
// TC : O(NlogN)
// SC :
void kLargestElemsBruteforce(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    while (k--)
    {
        cout << arr[--n] << " ";
    }
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(NlogK)
// SC :
int kLargestElemsOptimal(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < arr.size(); i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
        {
            minH.pop();
        }
    }

    // while (minH.size() > 1)
    // {

    //     minH.pop();
    // }
    return minH.top();
}

/*
3. Sort a K sorted array || Sort nearly sorted array
ANS : Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time.
Means: arr[i]'s next or prev elem will be in range of k
Input :  arr[] = {6, 5, 3, 2, 8, 10, 9} k = 3   || Output : {2, 3, 5, 6, 8, 9, 10}
*/
// Bruteforce ----------->
// TC :
// SC :
// just sort the array and return it
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(NlogK)
// SC : O(N) for return ans
vector<int> nearlySortedArrayOptimal(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
        {
            ans.push_back(minH.top());
            minH.pop();
        }
    }
    while (minH.size() > 0)
    {
        ans.push_back(minH.top());
        minH.pop();
    }
    return ans;
}

/*
4. K closest number
ANS : Given an unsorted array and two numbers x and k, find k closest values to x.
Means: find out 3 numbers that are close to 5
Input :   arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3 || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Mathematecally 5-arr[i] so arr will be=-5, 3, -9, 1, -2, -1
// 1, -2 , -1 are small so return this index's numbers for that you have to sort this index array
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(NlogK) cz ans are 3 so its constant
// SC :
vector<int> kclosestNumbersOptimal(vector<int> &arr, int x, int k)
{
    // In this max heap sorting depands on maxH.first();
    priority_queue<pair<int, int>> maxH;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        // We're saving here the diffrence
        maxH.push({abs(arr[i] - x), arr[i]});
        if (maxH.size() > k)
            maxH.pop();
    }
    while (maxH.size() > 0)
    {
        ans.push_back(maxH.top().second);
        maxH.pop();
    }
    return ans;
}

/*
5. Top K frequent numbers
ANS : Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top (According to their decreasing frequency) every time a new number is read. We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency.
Input :   arr[] = {1,1,1,2,2,3} k = 4 || Output : 2 1
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(M log K). M=no of unique elems
// SC : O(M + K), where M is the number of unique elements and K is the value of k.

vector<int> topKFrequentOptimal(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    // Define a min-heap based on frequency
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

    // Populate the min-heap with frequency and element pairs
    for (auto it : mpp)
    {
        minH.push({it.second, it.first});
        if (minH.size() > k)
            minH.pop();
    }
    while (!minH.empty())
    {
        ans.push_back(minH.top().second);
        minH.pop();
    }
    return ans;
}

/*
6. Frequency sort
ANS : Print the elements of an array in the increasing frequency if 2 numbers have same frequency then print the one which came first.
Input : arr[] = {1,1,2,2,2,3}}  || Output : arr[] = [3,1,1,2,2,2]
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :O(M * K * log K).
// SC :O(M)
vector<int> printElementsByFrequencyCompare(vector<int> &arr)
{
    vector<int> ans;
    unordered_map<int, int> frequencyMap;

    // Count the frequency of each element
    for (int i = 0; i < arr.size(); i++)
    {
        frequencyMap[arr[i]]++;
    }

    // Define a min-heap with custom comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

    // Populate the min-heap with frequency and element pairs
    for (auto it : frequencyMap)
    {
        minHeap.push({it.first, it.second});
    }

    // Print the elements in increasing frequency
    while (!minHeap.empty())
    {
        pair<int, int> top = minHeap.top();
        minHeap.pop();
        for (int i = 0; i < top.second; i++)
            ans.push_back(top.first);
    }
    return ans;
}
// Optimal ---------->
// TC :O(M * K * log K).
// SC :O(M)
vector<int> printElementsByFrequency(vector<int> &arr)
{
    vector<int> ans;
    unordered_map<int, int> m;
    for (auto it : arr)
        m[it]++;

    priority_queue<pair<int, int>> maxH;
    for (auto &i : m)
        maxH.push({-i.second, i.first});

    vector<int> v;
    while (!maxH.empty())
    {
        for (int i = 0; i < -(maxH.top().first); i++)
        {
            v.push_back(maxH.top().second);
        }
        maxH.pop();
    }
    for (auto it : v)
        ans.push_back(it);
    return ans;
}

/*
7. K closest point to origin
ANS : Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.
Note: The distance between two points on a plane is the Euclidean distance.
Assume that you draw a x,y axis and point are placed. your origin is 0,0 . you need to return which points are close to origin you have to return K ans.
So you need to find distance from origin to points the formula is sqrt(x^2+y^2)
Input : point = [[3, 3], [5, -1], [-2, 4]], K = 2   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(n * log(k)).
// SC : O(k)
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    // We used max heap bcz after data put in a priority_queue we have to take only 2 ans so we have to remove it from queue if we used min heap then we remove ans cz up to down is increasing and we need minimum ans
    priority_queue<pair<int, pair<int, int>>> maxH;
    vector<vector<int>> ans;
    for (int i = 0; i < points.size(); i++)
    {
        maxH.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
        if (maxH.size() > k)
            maxH.pop();
    }
    while (!maxH.empty())
    {
        ans.emplace_back(vector<int>{maxH.top().second.first, maxH.top().second.second});
        maxH.pop();
    }
    return ans;
}

/*
8. Connect Ropes to minimise the cost
ANS : There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.
Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38. .
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(NlogN)
// SC :O(N)
int connectSticks(vector<int> &sticks)
{
    int ans = 0;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (const int stick : sticks)
        minHeap.push(stick);

    while (minHeap.size() > 1)
    {
        const int x = minHeap.top();
        minHeap.pop();
        const int y = minHeap.top();
        minHeap.pop();
        ans += x + y;
        minHeap.push(x + y);
    }

    return ans;
}

/*
9. Sum of elems between K1 smallest and K2 smallest numbers
ANS : Given an array of integers and two numbers k1 and k2. Find the sum of all elements between given two k1’th and k2’th smallest elements of the array. It may  be assumed that all elements of array are distinct.
Input :  arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6   || Output :26
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N * log(K1 + K2)).
// SC : O(K1 + K2).
int sumOfElemsK1K2(vector<int> &arr, int k1, int k2)
{
    if (k1 > k2 || k1 <= 0 || k2 > arr.size())
    {
        // Invalid input parameters
        return 0;
    }

    int k1_smallest = kthSmallestElementOptimal(arr, k1);
    int k2_smallest = kthSmallestElementOptimal(arr, k2);

    int sum = 0;
    for (auto it : arr)
    {
        if (it > k1_smallest && it < k2_smallest)
        {
            sum += it;
        }
    }

    return sum;
}
// ==============================TUF PLAYLIST=====================================>>

/*
10.  Implement a priority queue
ANS : You have to implement the pop function of Max Priority Queue and implement using a heap.
Functions :
a) push(int x) : 'x' has to be inserted in the priority queue. This has been implemented already
b) pop() : return the maximum element in the priority queue, if priority queue is empty then return '-1'.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
11. Min Heap and Max Heap Implementation
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
12. Check if an array represents a min-heap or not
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(N)
// SC :O(1)
bool isMinHeapBruteforce(int arr[], int n)
{
    // Check each node to ensure the min-heap property
    for (int i = 0; i < n; ++i)
    {
        // Calculate the indices of the left and right children
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Check if left child exists and is smaller than the current node
        if (leftChild < n && arr[leftChild] < arr[i])
        {
            return false;
        }

        // Check if right child exists and is smaller than the current node
        if (rightChild < n && arr[rightChild] < arr[i])
        {
            return false;
        }
    }

    // If all nodes satisfy the min-heap property, return true
    return true;
}

// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
13. Convert min Heap to max Heap
ANS : You are given an array of size ‘N’ which is an array representation of min-heap.
You need to convert this min-heap array representation to a max-heap array representation. Return the max-heap array representation.
Input : min=[1,2,3,6,7,8]  || Output : max heap: [8,7,3,6,2,1]
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(NlogN)
// SC :O(1)
void make_heap(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i)
    {
        // Heapify the subtree rooted at index i
        int parent = i;
        int leftChild = 2 * parent + 1;

        while (leftChild < n)
        {
            int maxChild = leftChild;
            int rightChild = leftChild + 1;

            // Check if the right child exists and is greater
            if (rightChild < n && arr[rightChild] > arr[leftChild])
            {
                maxChild = rightChild;
            }

            // Swap if the parent is less than the maximum child
            if (arr[parent] < arr[maxChild])
            {
                swap(arr[parent], arr[maxChild]);
                parent = maxChild;
                leftChild = 2 * parent + 1;
            }
            else
            {
                break;
            }
        }
    }
}
void sort_heap(vector<int> &arr)
{
    int n = arr.size();

    // Convert the heap into a sorted array
    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]); // Move the root (maximum element) to the end
    }
    make_heap(arr); // Heapify the reduced heap
}
vector<int> MinToMaxHeap(int n, vector<int> &arr)
{
    // MAKE HEAP AND SORT HEAP IS STL FUNCTION
    // Use make_heap to convert the vector to a min-heap
    make_heap(arr.begin(), arr.end(), greater<int>());
    // Sort the vector in ascending order to convert it to a max-heap
    sort_heap(arr.begin(), arr.end(), greater<int>());

    return arr;
}

/*
14. Kth largest element in an array
ANS : Given an unsorted array, print Kth Largest and Smallest Element from an unsorted array.
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
void kth_Largest_And_Smallest_By_AscendingOrder(vector<int> &arr, int k)
{

    sort(arr.begin(), arr.end());
    int n = arr.size();

    cout << "kth Largest element " << arr[n - k] << ", "
         << "kth Smallest element " << arr[k - 1];
}
// Optimal ---------->
// TC :
// SC :
void kth_LargestOptimal(vector<int> &arr, int k)
{

    priority_queue<int> maxH;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        maxH.push(arr[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        maxH.pop();
        f--;
    }

    cout << "Kth Largest element " << maxH.top() << "\n";
}
// Optimal 2---------->
// TC : O(N)
// SC :O(1)
int partition2(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int l = left + 1;
    int r = right;
    while (l <= r)
    {
        if (arr[l] < pivot && arr[r] > pivot)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        if (arr[l] >= pivot)
        {
            l++;
        }
        if (arr[r] <= pivot)
        {
            r--;
        }
    }
    swap(arr[left], arr[r]);
    return r;
}

int kth_Largest_Element(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1, kth;
    while (1)
    {
        int idx = partition2(arr, left, right);
        if (idx == k - 1)
        {
            kth = arr[idx];
            break;
        }
        if (idx < k - 1)
        {
            left = idx + 1;
        }
        else
        {
            right = idx - 1;
        }
    }
    return kth;
}

/*
15. Kth smallest element in an array
ANS :Aditya 2
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
16. Sort K sorted array
ANS :
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
17. Merge M sorted Lists
ANS : Given 'k' sorted linked lists, each list is sorted in increasing order. You need to merge all these lists into one single sorted list. You need to return the head of the final linked list.
Input :  || Output :
*/
// Bruteforce ----------->
// Time Complexity: O(N * logN)
// Space Complexity: O(N)

Node *mergeKListsBruteforce(vector<Node *> &listArray)
{

    int k = listArray.size();

    if (k == 0)
    {
        return NULL;
    }

    vector<int> helper;

    // Insert nodes in a helper array.
    for (int i = 0; i < k; i++)
    {
        Node *curNode = listArray[i];

        while (curNode != NULL)
        {
            helper.push_back(curNode->data);
            curNode = curNode->next;
        }
    }

    // Sort the array.
    sort(helper.begin(), helper.end());

    Node *head = NULL, *tail = NULL;

    // Convert into a linked list.
    for (int i = 0; i < helper.size(); i++)
    {
        Node *newNode = new Node(helper[i]);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// Time Complexity : O(N *logK)
// Space Complexity : O(K)
// Node *mergeKListsOptimal(vector<Node *> &listArray)
// {
//     int k = listArray.size();
//     if (k == 0)
//     {
//         return NULL;
//     }

//     priority_queue<Node *, vector<Node *>, Compare> helperPQ;

//     // Push into the queue.
//     for (int i = 0; i < k; i++)
//     {
//         if (listArray[i] != NULL)
//         {
//             helperPQ.push(listArray[i]);
//         }
//     }

//     Node *head = NULL, *tail = NULL;

//     // Add nodes while queue is non empty.
//     while (helperPQ.size() > 0)
//     {
//         Node *minNode = helperPQ.top();
//         helperPQ.pop();

//         if (minNode->next != NULL)
//         {
//             helperPQ.push(minNode->next);
//             minNode->next = NULL;
//         }

//         if (head == NULL)
//         {
//             head = minNode;
//             tail = minNode;
//         }
//         else
//         {
//             tail->next = minNode;
//             tail = tail->next;
//         }
//     }

//     return head;
// }
/*
18. Replace elements by its rank in the array
ANS : Given an array of N integers, the task is to replace each element of the array by its rank in the array.
Input : 20 15 26 2 98 6 || Output :  4 3 5 1 6 2
*/
// Bruteforce ----------->
// TC : O(N*N)
// SC :O(N)
vector<int> replaceWithRankBruteforce(vector<int> &arr, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                s.insert(arr[j]);
            }
        }
        ans.push_back(s.size() + 1);
    }
    return ans;
}
// Better ----------->
// TC : O(n)+O(nlogn)+O(n)
// SC : O(n)
vector<int> replaceWithRankBetter(vector<int> &arr, int n)
{
    vector<int> ans;

    map<int, int> mp;
    int temp = 1;
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        brr[i] = arr[i];
    }
    sort(brr, brr + n);
    for (int i = 0; i < n; i++)
    {
        // if element is previously not store in the map
        if (mp[brr[i]] == 0)
        {
            mp[brr[i]] = temp;
            temp++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans.push_back(mp[arr[i]]);
    }
    return ans;
}
// Optimal ---------->
// TC : O(NlogN)
// SC :O(N)
vector<int> replaceWithRankOptimal(vector<int> &arr, int n)
{
    // Create a min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min heap
    for (int i = 0; i < n; ++i)
    {
        minHeap.push(arr[i]);
    }

    // Replace elements with their ranks
    for (int i = 0; i < n; ++i)
    {
        int current = arr[i];

        // Find the rank of the current element in the min heap
        int rank = 1;
        vector<int> temp;

        while (!minHeap.empty())
        {
            if (minHeap.top() == current)
            {
                arr[i] = rank;
                break;
            }
            temp.push_back(minHeap.top());
            minHeap.pop();
            rank++;
        }

        // Restore the min heap
        for (int val : temp)
        {
            minHeap.push(val);
        }
    }

    return arr;
}

/*
19. Task Scheduler
ANS : Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
Return the least number of units of times that the CPU will take to finish all the given tasks.
Input : tasks = ["A","A","A","B","B","B"], n = 2 || Output : 8
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// Time complexity: O(N)
// Space complexity: O(N) or O(U), depending on the number of unique tasks.
int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> mp;
    int count = 0;
    for (auto e : tasks)
    {
        mp[e]++;
        count = max(count, mp[e]);
    }

    int ans = (count - 1) * (n + 1);
    for (auto e : mp)
        if (e.second == count)
            ans++;
    return max((int)tasks.size(), ans);
}

/*
20.  Hand of Straights
ANS : Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
Input : [1,2,3,4,5] 4 || Output : false
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(NlogN)
// SC :O(N)
bool isNStraightHand(vector<int> &hand, int groupSize)
{
    if (hand.size() % groupSize != 0)
        return false;

    int curr = 0, prev = -1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto h : hand)
        pq.push(h);

    vector<int> tmp;
    while (!pq.empty())
    {
        int t = pq.top();
        pq.pop();

        // only add if the group is new or if the next number is consecutive
        if (prev == -1 || t - prev == 1)
        {
            prev = t;
            curr++;
        }
        else
        {
            // save all hands which cannot be added in current group
            //  these will be pushed back into pq once a new group starts
            tmp.push_back(t);
        }

        if (curr == groupSize)
        {
            curr = 0;
            prev = -1;

            for (auto e : tmp)
                pq.push(e);

            tmp = {};
        }
    }
    // if a group is incomplete then curr will be > 0.
    return curr ? false : true;
}

/*
21. Design Twitter
ANS : Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
22. Connect `n` ropes with minimal cost
ANS : Aditya 8
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
23.
ANS :
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
24.
ANS :
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
25.
ANS :
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
26. K most frequent elements
ANS : Aditya 5
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

// ================================MAIN START=================================>>
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./i.txt", "r", stdin);
    //     freopen("./o.txt", "w", stdout);
    // #endif
    /*
        Some short function
           int maxi = *max_element(arr.begin(), arr.end());
            int sum = accumulate(arr.begin(), arr.end(), 0);
    */
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    // cout << "Smallest Elem is " << kthSmallestElementBruteforce(arr, 3);
    // cout << "Smallest Elem is " << kthSmallestElementOptimal(arr, 3);
    // kLargestElemsBruteforce(arr, 3);
    // cout << endl;
    cout << kLargestElemsOptimal(arr, 3);
    // vector<int> ans = nearlySortedArrayOptimal(arr, 3);
    // vector<int> ans = kclosestNumbersOptimal(arr, 7, 3);
    // vector<int> ans = topKFrequentOptimal(arr, 2);
    // printVector(ans);
    // vector<int> arr1 = printElementsByFrequencyCompare(arr);
    // printVector(arr1);
    // cout << endl;
    // cout << endl;
    // vector<int> arr2 = printElementsByFrequency(arr);
    // printVector(arr2);
    // cout << "Ans is " << sumOfElemsK1K2(arr, 3, 6);
    // cout << endl;w
    // sort(arr.begin(), arr.end());
    // printVector(arr);
    // int arr[6] = {2, 4, 5, 8, 9, 22};
    // isMinHeapBruteforce(arr, 6) ? cout << "Yes" : cout << "No";
    // vector<int> arr = {20, 15, 26, 2, 98, 6};
    // vector<int> ans = MinToMaxHeap(arr.size(), arr);
    // printVector(ans);
    // kth_Largest_And_Smallest_By_AscendingOrder(arr, 3);
    // cout << kth_Largest_Element(arr, 3);
    // cout << endl;
    // kth_LargestOptimal(arr, 3);
    // vector<int> ans = replaceWithRankBruteforce(arr, arr.size());
    // vector<int> ans = replaceWithRankBetter(arr, arr.size());
    // vector<int> ans = replaceWithRankOptimal(arr, arr.size());

    // printVector(ans);

    // End code here-------->>

    return 0;
}
