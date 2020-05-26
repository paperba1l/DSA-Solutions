vector<int> Solution::allFactors(int A)
{

    vector<int> vec;
    int q = sqrt(A);
    for (int i = 1; i <= q; i++)
    {

        if (A % i == 0)
        {
            vec.push_back(i);
            if (i * i != A)
                vec.push_back(A / i);
        }
    }

    sort(vec.begin(), vec.end());
    return vec;
}
