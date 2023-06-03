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
        this->original_order.remove(element);
        this->sorted.erase(element);
        this->prime.remove(element);
        this->cross.remove(element);
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

    MagicalContainer::PrimeIterator::PrimeIterator(){// default
        this->iter = this->prime_ptr->begin();
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other){ // copy
        this->iter = other.iter;
        this->prime_ptr = other.prime_ptr;
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
        return std::distance(this->prime_ptr->begin(), this->iter) == std::distance(other.prime_ptr->begin(), other.iter);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        return std::distance(this->prime_ptr->begin(), this->iter) > std::distance(other.prime_ptr->begin(), other.iter);;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        return std::distance(this->prime_ptr->begin(), this->iter) < std::distance(other.prime_ptr->begin(), other.iter);
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
        return std::distance(this->prime_ptr->begin(), this->iter) != std::distance(other.prime_ptr->begin(), other.iter);
    }

    int MagicalContainer::PrimeIterator::operator*() const{
        return *(this->iter); // gives the actual value
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
        MagicalContainer::PrimeIterator ans(*this);
        ans.iter = this->prime_ptr->begin();
        return ans;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
        MagicalContainer::PrimeIterator ans(*this);
        ans.iter = this->prime_ptr->end();
        return ans;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        return *this;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(){// default
        this->iter = this->sorted_ptr->begin();
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container){
        this->iter = container.sorted.begin();
        this->sorted_ptr = &container.sorted;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other){ // copy
        this->iter = other.iter;
        this->sorted_ptr = other.sorted_ptr;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        this->iter++;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return std::distance(this->sorted_ptr->begin(), this->iter) == std::distance(other.sorted_ptr->begin(), other.iter);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        return std::distance(this->sorted_ptr->begin(), this->iter) > std::distance(other.sorted_ptr->begin(), other.iter);;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return *(this->iter); // gives the actual index
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

    MagicalContainer::SideCrossIterator::SideCrossIterator(){// default
        this->iter = this->cross_ptr->begin();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container){
        this->iter = container.cross.begin();
        this->cross_ptr = &container.cross;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other){ // copy
        this->iter = other.iter;
        this->cross_ptr = other.cross_ptr;
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