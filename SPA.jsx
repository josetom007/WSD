import React from "react";
import "./spa.css";

const SPA = () => {
  return (
    <div>
      {/* NAVBAR */}
      <nav className="navbar">
        <a href="#home">Home</a>
        <a href="#products">Products</a>
        <a href="#about">About</a>
        <a href="#contact">Contact</a>
      </nav>

      {/* HOME */}
      <section id="home" className="page">
        <h1>Snatch Fitness</h1>
        <p>Premium fitness fashion for men.</p>

        <a href="#products" className="btn">
          View Products
        </a>

        <p className="filler">
          Designed for performance. Built for style. Made for athletes.
        </p>
      </section>

      {/* PRODUCTS */}
      <section id="products" className="page">
        <h2>Featured Products</h2>
        <ul>
          <li>Gym T-Shirts</li>
          <li>Compression Wear</li>
          <li>Joggers</li>
          <li>Workout Hoodies</li>
        </ul>

        <p className="filler">
          High-quality materials that move with your body during workouts.
        </p>
      </section>

      {/* ABOUT */}
      <section id="about" className="page">
        <h1>About Snatch</h1>
        <p>
          Snatch is a fitness fashion brand focused on modern gym wear,
          comfort, and performance.
        </p>

        <p className="filler">
          We believe fitness wear should inspire confidence and power.
        </p>
      </section>

      {/* CONTACT */}
      <section id="contact" className="page">
        <h1>Contact Us</h1>
        <p>Email: support@snatchfitness.com</p>
        <p>Instagram: @snatch.fitness</p>

        <p className="filler">
          Reach out for collaborations, support, or wholesale inquiries.
        </p>
      </section>
    </div>
  );
};

export default SPA;
