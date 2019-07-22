#ifdef FORMULA_H
#error Already included
#else
#define FORMULA_H

class formula
{
    public:
        struct param_set1
        {
            double freq;
            double sigma;
        };

    public:
        formula(param_set1 const &param);
        ~formula();

        double frequency() const;
        double sigma() const;
        double delta() const;

    private:
        double const m_freq;
        double const m_sigma;
        double const m_delta;

    public:
        formula() = delete;
        formula(const formula &instance) = delete;
        formula(const formula &&instance) = delete;
        formula &operator=(const formula &instance) = delete;
        formula &operator=(const formula &&instance) = delete;
};

#endif
