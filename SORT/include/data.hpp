
namespace data
{
    static inline void gen_signal(std::vector<int> &arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = sin(i / 2) * WINDOW_HEIGHT; // rand() % WINDOW_HEIGHT;
        }
    }

    static inline void gen_rand(std::vector<int> &arr, int size)
    {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % int(WINDOW_HEIGHT);
        }
    }

    static inline void gen_backward(std::vector<int> &arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = -i;
        }
    }

    std::vector<int> generate_data(gen_type generation_type, int num_points)
    {
        std::vector<int> arr;
        arr.resize(num_points);
        switch (generation_type)
        {
        case gen_type::stochastic:
            gen_rand(arr, NUM_ELEMENTS);
            break;
        case gen_type::backward:
            gen_backward(arr, NUM_ELEMENTS);
            break;
        case gen_type::signalsine:
            gen_signal(arr, NUM_ELEMENTS);
            break;
        }
        return arr;
    }

}