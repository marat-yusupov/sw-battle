namespace sw::bl::models
{
    class Map
    {
    private:
        int _width;
        int _height;

    public:
        Map(int width, int height);

        int width() const;

        int height() const;
    };
}
