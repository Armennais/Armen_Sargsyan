import React from 'react';
import ReactDOM from 'react-dom/client';
import { BrowserRouter,Routes,Route,Link } from 'react-router-dom';
import './styles/index.css';
import AppFC from './App.js';
import Main from './main';
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
    
    <BrowserRouter >
        <nav className='navbar'>
            <Link to="/">HOME</Link>
            <Link to="/films">FILMS</Link>
        </nav>
    <Routes>
        <Route path = '/' element={<Main/>}/>
        <Route path='/films' element={<AppFC/>}/>
    </Routes>
    </BrowserRouter>
   
);

