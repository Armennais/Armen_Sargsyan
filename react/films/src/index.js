import React from 'react';
import ReactDOM from 'react-dom/client';
import { BrowserRouter,Routes,Route,Link } from 'react-router-dom';
import './styles/index.css';
import AppFC from './App.js';
import Main from './main';
import Layout from './Components/Layout';
import FilmInfo from './Components/FilmInfo'
const root = ReactDOM.createRoot(document.getElementById('root'));

root.render(
    
    <BrowserRouter >
        
    <Routes>
        <Route path='/' element = {<Layout/>}>
            <Route index element={<Main/>}/>
            <Route path='/films' element={<AppFC/>}/>
            <Route path='/film/:id' element ={<FilmInfo />}>
            </Route>
        </Route>
    </Routes>
    </BrowserRouter>
   
);

