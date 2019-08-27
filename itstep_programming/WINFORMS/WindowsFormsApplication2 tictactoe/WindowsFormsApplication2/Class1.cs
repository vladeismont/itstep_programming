using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication2
{
    class Class1
    {
        public enum State
        {
            x,o,none
        }
        public State[,] Field{get; private set;}
        public int CountStep{get; private set;}
        public State Winner{get; private set;}
        public bool GameOver{get; private set;}
        public State CurrentMove{get; private set;}
        public delegate void UpdateViewDelegate();
        public event UpdateViewDelegate UpdateView;
        public void MakeMove(int i, int j, State side)
        {
            if (GameOver)
            {
                throw new Exception("game is already over!");
            }
            if (i < 0 || i > 2 || j < 0 || j > 2)
            {
                throw new IndexOutOfRangeException("index is out of field");
            }
            if (side != CurrentMove)
            {
                throw new Exception("not your turn");
            }
            if (Field[i, j] != State.none)
            {
                throw new Exception("not empty");
            } 
            CountStep++;
            Field[i, j] = side;
            CheckForGameOver();
            CurrentMove=side==State.o?State.x:State.o;
        }

        private void CheckForGameOver()
        {
            if (CountStep < 5) return;
            throw new NotImplementedException();
        }
    }
}
