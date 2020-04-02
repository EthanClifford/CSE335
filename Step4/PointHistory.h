/**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    /// The number of potato lists.
    const static int NumLists = 2;

    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);

    /** Iterator that iterates over the history of points the mouse has touched */
    class Iter
    {
    public:
        /** Constructor
        * \param pointHistory The history of points we are iterating over
        * \param pos The current position in the lists that we are at
        * \param listNum The current list that we are working in
        */
        Iter(CPointHistory* pointHistory, int pos, int listNum) : mPointHistory(pointHistory), 
            mPos(pos), mListNum(listNum) {}

        /** Test for end of the iterator
        * \param other The other operand
        * \returns True if this poistion equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            if (mPos != other.mPos || mListNum != other.mListNum)
            {
                return true;
            }
            return false;
        }

        /** Get value at current position
        * \returns Value at mPos in the collection */
        Gdiplus::Point operator *() const 
        {
            return mPointHistory->mPotatoLists[mListNum][mPos]; 
        }

        /** Increment the iterator
        * \returns Reference to this iterator */
        const Iter& operator++()
        {
            mListNum++;
            if (mListNum >= NumLists)
            {
                mListNum = 0;
                mPos++;
            }
            return *this;
        }

    private:
        CPointHistory* mPointHistory;   ///< Point History we are iterating over
        int mPos;   ///< Position in the collection
        int mListNum;   ///< List that we are currently in
    };

    /** Get an iterator for the beginning of the collection
    * \returns Iter object at poistion 0 */
    Iter begin() { return Iter(this, 0, 0); }

    /** Get an iterator for the end of the collection
    * \returns Iter object at position past the end */
    Iter end() { return Iter(this, mPotatoLists[mCurrentList].size(), mCurrentList); }

protected:
    /// Data is stored in alternating locations in 
    /// the multiple hot potato lists.
    std::vector<Gdiplus::Point> mPotatoLists[NumLists];

    /// The current list we are adding points to. Each time
    /// we add a point, we will add it to this list, then 
    /// change mCurrentList to change to the next list.
    int mCurrentList = 0;
};

