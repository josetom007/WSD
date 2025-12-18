// src/LoginForm.jsx
import React from "react";
import "./App.css"; // Make sure this CSS file exists

const LoginForm = () => {
    return (
        <form className="cover" onSubmit={(e) => e.preventDefault()}>
            <h1>Login <span>Here!!</span></h1>
            <input type="text" placeholder="Enter Name" name="username" />
            <input type="password" placeholder="Enter Password" name="password" />
            <button type="submit">SUBMIT</button>
        </form>
    );
};

export default LoginForm;