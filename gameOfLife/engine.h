#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
   protected:
      int nw, nk;
      bool **arr, **temp;
   protected:
      Engine(int nnw, int nnk);
      virtual ~Engine() {}
      void analyze();
   private:
      int sum(int i, int j);
      Engine(const Engine& e);
      Engine& operator=(const Engine& e);
};

#endif
