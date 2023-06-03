#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <list>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <set>
#include "MagicalContainer.hpp"
namespace ariel{
    MagicalContainer::MagicalContainer(){
        this->back = true;
    }

    MagicalContainer::~MagicalContainer(){
        this->original_order.clear();
        this->sorted.clear();
        this->prime.clear();
        this->cross.clear();
    }

    void MagicalContainer::addElement(int element){
        this->original_order.push_back(element);
        this->sorted.insert(element);
        if (isPrime(element)){
            this->prime.push_back(element);
        }
        if(this->back){
            this->cross.push_back(element);
        }
        else{
            this->cross.push_front(element);
        }
        this->back = !this->back;
    }

    void MagicalContainer::removeElement(int element){
    }

    int MagicalContainer::size() const{
        return this->original_order.size();
    }

    bool MagicalContainer::contains(int element){
        return this->sorted.contains(element);
    }

    void MagicalContainer::updatePrimeContainer(){
        this->prime.clear();
        for (auto it = this->original_order.begin(); it != this->original_order.end(); ++it){
            if (isPrime(*it)){
                this->prime.push_back(*it);
            }
        }
    }

    bool MagicalContainer::isPrime(int num){
        if (num <= 1){
            return false;
        }
        int sqroot = std::sqrt(num);
        for (int i = 2; i < sqroot; i++){
            if (num % i == 0){
                return false;
            }
        }
        return true;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container){
        this->iter = container.prime.begin();
        this->prime_ptr = &container.prime;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        this->iter++;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        return this->iter == other.iter;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const{
        return 0;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
        MagicalContainer container;
        MagicalContainer::PrimeIterator ans(container);
        return ans;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        return *this;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container){
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return 0;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
        MagicalContainer container;
        AscendingIterator ans(container);
        return ans;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        return *this;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container){
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const{
        return 0;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
        MagicalContainer container;
        MagicalContainer::SideCrossIterator ans(container);
        return ans;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        return *this;
    }
}