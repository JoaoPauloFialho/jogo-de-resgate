#ifndef GAMEBASE_H
#define GAMEBASE_H

class GameBase{
    private:
    public:
        GameBase();
        virtual void atualizar()=0;
        virtual void inicializar()=0;
};

#endif