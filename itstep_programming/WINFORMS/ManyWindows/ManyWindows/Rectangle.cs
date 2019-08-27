using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ManyWindows.Shapes
{
    class RectanglE:Shape
    {
        float a, b;
        public RectanglE(float x, float y, float m, float n)
        {
            point = new System.Drawing.PointF(x, y);
            a = m;
            b = n;
        }
        public override void Paint(System.Drawing.Graphics g)
        {
            g.FillRectangle(brush, point.X, point.Y, a, b);
            g.DrawRectangle(pen, point.X, point.Y, a, b);
        }

        public override bool isInside(float X, float Y)
        {
            var click = new System.Drawing.PointF(X, Y);

            if (Distance(click, point, a, b))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
