#include "PMerge.hpp"

//----- UTILS -----//

void    print(std::vector<int> &vec) {
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << ((i == vec.size() - 1) ? "\n" : ", ");
}

void    print(std::deque<int> &vec) {
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << ((i == vec.size() - 1) ? "\n" : ", ");
}

void    swap(int &n1, int &n2) {
    int tm;

    tm = n1;
    n1 = n2;
    n2 = tm;
}

int clamp(const int value, const int lower, const int upper) {
    return value < lower ? lower : (upper < value ? upper : value);
}

size_t  jacobsthal(size_t n) {
    if (n == 0)
        return (0);
    else if (n == 1)
        return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}



std::vector<int>    vcJacobsthalSequence(std::vector<int> &pend) {
    std::vector<int>    sequence;
    int                 index = 3;

    while (jacobsthal(index) < pend.size() - 1) {
        sequence.push_back(jacobsthal(index));
        ++index;
    }
    return (sequence);
}

std::deque<int>    dqJacobsthalSequence(std::deque<int> &pend) {
    std::deque<int>     sequence;
    int                 index = 3; 

    while (jacobsthal(index) < pend.size() - 1) {
        sequence.push_back(jacobsthal(index));
        ++index;
    }
    return (sequence);
}



//----- PMERGE -----//

std::vector<int>   vcParseData(const char **args) {
    std::vector<int>    vec;
    
    for (size_t i = 0; args[i] != NULL; ++i) {
        int                 num;
        std::stringstream   ss(args[i]);
        
        ss >> num;
        if (ss.fail() || !ss.eof() || num <= 0)
            throw std::runtime_error("Error: Bad input");
        else
            vec.push_back(num);
    }
    return (vec);
}

std::deque<int>   dqParseData(const char **args) {
    std::deque<int>    dq;
    
    for (size_t i = 0; args[i] != NULL; ++i) {
        int                 num;
        std::stringstream   ss(args[i]);
        
        ss >> num;
        if (ss.fail() || !ss.eof() || num <= 0)
            throw std::runtime_error("Error: Bad input");
        else
            dq.push_back(num);
    }
    return (dq);
}



std::vector< std::pair<int, int> >  &vcSortEachPair(std::vector< std::pair<int, int> > &pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first < pairs[i].second)
            swap(pairs[i].first, pairs[i].second);
    }
    return (pairs);
}

std::deque< std::pair<int, int> >   &dqSortEachPair(std::deque< std::pair<int, int> > &pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first < pairs[i].second)
            swap(pairs[i].first, pairs[i].second);
    }
    return (pairs);
}



std::vector< std::pair<int, int> > vcMerge(
    std::vector< std::pair<int, int> > &left,
    std::vector< std::pair<int, int> > &right
) {
    std::vector< std::pair<int, int> >  merged;
    
    size_t i = 0;
    size_t j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].first < right[j].first)
            merged.push_back(left[i++]);
        else
            merged.push_back(right[j++]);
    }

    while (i < left.size())
        merged.push_back(left[i++]);

    while (j < right.size())
        merged.push_back(right[j++]);

    return (merged);
}

std::vector< std::pair<int, int> > vcSortPairs(std::vector< std::pair<int, int> > &pairs) {
    if (pairs.size() <= 1)
        return pairs;

    size_t mid = pairs.size() / 2;
    std::vector< std::pair<int, int> >  left(pairs.begin(), pairs.begin() + mid);
    std::vector< std::pair<int, int> >  right(pairs.begin() + mid, pairs.end());

    std::vector< std::pair<int, int> >  sortedLeft = vcSortPairs(left);
    std::vector< std::pair<int, int> >  sortedRight = vcSortPairs(right);

    return (vcMerge(sortedLeft, sortedRight));
}

std::deque< std::pair<int, int> > dqMerge(
    std::deque< std::pair<int, int> > &left,
    std::deque< std::pair<int, int> > &right
) {
    std::deque< std::pair<int, int> >  merged;
    
    size_t i = 0;
    size_t j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].first < right[j].first)
            merged.push_back(left[i++]);
        else
            merged.push_back(right[j++]);
    }

    while (i < left.size())
        merged.push_back(left[i++]);

    while (j < right.size())
        merged.push_back(right[j++]);

    return (merged);
}

std::deque< std::pair<int, int> > dqSortPairs(std::deque< std::pair<int, int> > &pairs) {
    if (pairs.size() <= 1)
        return pairs;

    size_t mid = pairs.size() / 2;
    std::deque< std::pair<int, int> >  left(pairs.begin(), pairs.begin() + mid);
    std::deque< std::pair<int, int> >  right(pairs.begin() + mid, pairs.end());

    std::deque< std::pair<int, int> >  sortedLeft = dqSortPairs(left);
    std::deque< std::pair<int, int> >  sortedRight = dqSortPairs(right);

    return (dqMerge(sortedLeft, sortedRight));
}





std::vector<int>    vcSort(std::vector< std::pair<int, int> > &pairs, int &odd) {
    int                         item;
    int                         last = 1;
    std::vector<int>            vec;
    std::vector<int>            pend;
    std::vector<int>            sequence;
    std::vector<int>            index;
    std::vector<int>::iterator  it;

    for (size_t i = 0; i < pairs.size(); ++i) {
        vec.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    sequence = vcJacobsthalSequence(pend);

    vec.insert(vec.begin(), pend[0]);
    index.push_back(0);
    pend.erase(pend.begin());

    for (size_t i = 0; i <= pend.size() && vec.size() > 2; ++i) {
        if (sequence.size() && last) {
            index.push_back(sequence[0]);
            item = pend[sequence[0] - 1];
            sequence.erase(sequence.begin());
            last = 0;
        } else {
            it = std::find(index.begin(), index.end(), i);
            if (it != index.end())
                ++i;
            item = pend[i - 1];
            index.push_back(i);
            last = 1;
        }
        it = std::lower_bound(vec.begin(), vec.end(), item);
        vec.insert(it, item);
    }

    if (odd != -1) {
        it = std::lower_bound(vec.begin(), vec.end(), odd);
        vec.insert(it, odd);
    }


    return (vec);
}

std::deque<int>     dqSort(std::deque< std::pair<int, int> > &pairs, int &odd) {
    int                         item;
    int                         last = 1;
    std::deque<int>             vec;
    std::deque<int>             pend;
    std::deque<int>             sequence;
    std::deque<int>             index;
    std::deque<int>::iterator   it;

    for (size_t i = 0; i < pairs.size(); ++i) {
        vec.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    sequence = dqJacobsthalSequence(pend);

    vec.insert(vec.begin(), pend[0]);
    index.push_back(0);
    pend.erase(pend.begin());

    for (size_t i = 0; i <= pend.size() && vec.size() > 2; ++i) {
        if (sequence.size() && last) {
            index.push_back(sequence[0]);
            item = pend[sequence[0] - 1];
            sequence.erase(sequence.begin());
            last = 0;
        } else {
            it = std::find(index.begin(), index.end(), i);
            if (it != index.end())
                ++i;
            item = pend[i - 1];
            index.push_back(i);
            last = 1;
        }
        it = std::lower_bound(vec.begin(), vec.end(), item);
        vec.insert(it, item);
    }

    if (odd != -1) {
        it = std::lower_bound(vec.begin(), vec.end(), odd);
        vec.insert(it, odd);
    }


    return (vec);
}


void    PMerge(const char **args) {

    try {
        std::vector<int>    original;

        double  vcDuration;
        double  dqDuration;
        clock_t startTime;
        clock_t endTime;
        int     odd;

        // VECTOR

        odd = -1;
        startTime = clock();

        std::vector<int>                    vc;
        std::vector< std::pair<int, int> >  vcPairs;

        vc = vcParseData(args);
        original = vc;
        
        for (size_t i = 1; i < vc.size(); i += 2)
            vcPairs.push_back(std::make_pair(vc[i - 1], vc[i]));

        if (vc.size() % 2)
            odd = vc.back();
        vc.clear();

        vcPairs = vcSortPairs(vcSortEachPair(vcPairs));
        vc = vcSort(vcPairs, odd);


        endTime = clock();

        vcDuration = (double)(endTime - startTime) / (CLOCKS_PER_SEC / 1000000);
        
        // DEQUE

        odd = -1;
        startTime = clock();

        std::deque<int>                     dq;
        std::deque< std::pair<int, int> >   dqPairs;

        dq = dqParseData(args);

        for (size_t i = 1; i < dq.size(); i += 2)
            dqPairs.push_back(std::make_pair(dq[i - 1], dq[i]));

        if (dq.size() % 2)
            odd = dq.back();
        dq.clear();

        dqPairs = dqSortPairs(dqSortEachPair(dqPairs));
        dq = dqSort(dqPairs, odd);

        endTime = clock();

        dqDuration = (double)(endTime - startTime) / (CLOCKS_PER_SEC / 1000000);


        std::cout << "Before:\n";
        print(original);
        std::cout << "After:\n";
        print(vc);
        // print(dq);

        std::cout << "Time to process a range of " << vc.size() \
        << " elements with std::vector: " << vcDuration << " us\n";

        std::cout << "Time to process a range of " << vc.size() \
        << " elements with std::deque: " << dqDuration << " us\n";

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
