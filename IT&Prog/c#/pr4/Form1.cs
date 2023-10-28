using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace task2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            Screen mainScreen = Screen.PrimaryScreen;
            int screenWidth = mainScreen.Bounds.Width;
            int screenHeight = mainScreen.Bounds.Height;

            Size = new Size(screenWidth, screenHeight); // Устанавливает ширину и высоту формы

        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            Screen mainScreen = Screen.PrimaryScreen;
            int screenWidth = mainScreen.Bounds.Width;
            int screenHeight = mainScreen.Bounds.Height;

            Color brownBright = ColorTranslator.FromHtml("#A9775B");

            Graphics graph = e.Graphics;
            Pen brown = new Pen(Color.SaddleBrown, 3);
            Pen penc = new Pen(Color.Black, 2);

            SolidBrush brownBrush = new SolidBrush(brownBright);
            SolidBrush blackBrush = new SolidBrush(Color.Black);

            Point[] points = new Point[]
            {
                new Point(755, 96),
                new Point(633, 87),
                new Point(607, 92),
                new Point(439, 184),
                new Point(437, 200),
                new Point(469, 347),
                new Point(480, 361),
                new Point(600, 363),
                new Point(615, 455),
                new Point(658, 583),
                new Point(714, 660),
                new Point(714, 800),
                new Point(1395, 800),
                new Point(1395, 695),
                new Point(926, 225),
                new Point(849, 224)
            };

            graph.FillEllipse(new SolidBrush(Color.SaddleBrown), 600, 55, 85, 85);
            graph.FillPolygon(brownBrush, points);
            graph.FillEllipse(new SolidBrush(Color.SaddleBrown), 710, 70, 85, 85);

            graph.FillPie(brownBrush, 455, 225, 940, 940, 270, 90);
            graph.FillPie(brownBrush, 605, 87, 46, 15, 185, 165);
            graph.FillPie(brownBrush, 436, 182, 15, 30, 90, 180);
            graph.FillPie(brownBrush, 469, 323, 69, 44, 145, 90);
            graph.FillPie(brownBrush, 644, 320, 196, 347, 100, 50);

            graph.DrawLine(brown, 439, 184, 607, 92);
            graph.DrawLine(brown, 633, 87, 755, 96);
            graph.DrawLine(brown, 755, 96, 849, 224);
            graph.DrawLine(brown, 849, 224, 926, 225);
            graph.DrawLine(brown, 437, 200, 469, 347);
            graph.DrawLine(brown, 480, 361, 600, 363);
            graph.DrawLine(brown, 615, 455, 658, 583);
            graph.DrawLine(brown, 714, 660, 714, 800);
            graph.DrawLine(brown, 1395, 695, 1395, 800);
            graph.DrawLine(brown, 600, 363, 615, 455);
            graph.DrawLine(new Pen(Color.Black, 3), 830, 680, 820, 800);

            graph.DrawArc(brown, 605, 87, 46, 15, 185, 160);
            graph.DrawArc(brown, 455, 225, 940, 940, 270, 90);
            graph.DrawArc(brown, 436, 182, 15, 30, 100, 180);
            graph.DrawArc(brown, 469, 323, 69, 44, 145, 32);
            graph.DrawArc(brown, 644, 320, 196, 347, 99, 40);
            graph.DrawArc(new Pen(Color.Black, 7), 590, 140, 55, 30, 180, 160);
            graph.DrawArc(new Pen(Color.Black, 5), 397, 300, 180, 30, 10, 135);
            graph.DrawArc(new Pen(Color.Black, 3), 1100, 500, 150, 350, 120, 150);

            graph.FillEllipse(blackBrush, 425, 175, 70, 40);
        }
    }
}
