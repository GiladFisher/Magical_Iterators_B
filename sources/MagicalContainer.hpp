#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <list>
#include <iterator>
#include <algorithm>
#include <set>
namespace ariel{
    class MagicalContainer{
        private:
            std::list<int> original_order; // all the values by order of insertion
            std::set<int> sorted; // sorted by value 
            std::list<int> prime; // only prime numbers by order of insertion 
            std::list<int> cross; // cross order
            void updatePrimeContainer();
            bool isPrime(int num);

        public:
            MagicalContainer();
            ~MagicalContainer();
            void addElement(int element);
            void removeElement(int element);
            int size() const; // return size of original container
            bool contains(int element);

            // friend class PrimeIterator;
            // friend class AscendingIterator;
            // friend class SideCrossIterator;
            
          
    

    class PrimeIterator{
    private:
        std::list<int>::iterator iter; // iterator for prime container
        std::list<int>* prime_ptr;
    public:
        PrimeIterator(); // default
        PrimeIterator(MagicalContainer &container); // init
        PrimeIterator(const PrimeIterator& other); // copy
        PrimeIterator& operator++(); // goes to next prime number
        bool operator>(const PrimeIterator& other) const; // compare indexes 
        bool operator<(const PrimeIterator& other) const;
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        int operator*() const; // get value
        PrimeIterator begin() const; // return iterator with index 0
        PrimeIterator end() const; // return size of prime container
        PrimeIterator& operator=(const PrimeIterator& other); //  Assignment operator
    };

    class AscendingIterator{
        private:
            std::set<int>::iterator iter; // iterator for sorted container 
            std::set<int>* sorted_ptr; 
        public:
            AscendingIterator(); // default
            AscendingIterator(MagicalContainer &container); // init
            AscendingIterator(const AscendingIterator& other); // copy
            AscendingIterator& operator++(); // goes to next 
            bool operator>(const AscendingIterator& other) const; // compare iterators 
            bool operator<(const AscendingIterator& other) const;
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            int operator*() const; // get value
            AscendingIterator begin() const; // return sorted_ptr.begin()
            AscendingIterator end() const; // return size of sorted container 
            AscendingIterator& operator=(const AscendingIterator& other); //  Assignment operator
    };

    class SideCrossIterator{
        private:
            std::list<int>::iterator iter; // iterator for cross container 
            std::list<int>* cross_ptr;
        public:
            SideCrossIterator(); // default
            SideCrossIterator(MagicalContainer &container); // init
            SideCrossIterator(const SideCrossIterator& other); // copy
            SideCrossIterator& operator++(); // goes to next 
            bool operator>(const SideCrossIterator& other) const; // compare iterators 
            bool operator<(const SideCrossIterator& other) const;
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            int operator*() const; // get value
            SideCrossIterator begin() const; // return cross_ptr.begin()
            SideCrossIterator end() const; // return size of cross container 
            SideCrossIterator& operator=(const SideCrossIterator& other); //  Assignment operator
    };
    };
}