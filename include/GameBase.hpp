#ifndef GAMEBASE_HPP
#define GAMEBASE_HPP

class GameBase{
    private:
    public:
        GameBase();
        virtual void atualizar()=0;
        virtual void inicializar()=0;
};

#endif