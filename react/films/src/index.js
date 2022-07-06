import React,{createContext} from 'react';
import ReactDOM from 'react-dom/client';
import { BrowserRouter,Routes,Route } from 'react-router-dom';
import './styles/index.css';
import AppFC from './Components/App.js';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
    <AppFC/>
);

