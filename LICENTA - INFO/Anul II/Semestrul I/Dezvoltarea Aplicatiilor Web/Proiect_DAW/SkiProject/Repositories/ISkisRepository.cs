using SkiProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Repositories
{
    public interface ISkisRepository
    {
        IQueryable<Ski> GetSkisIQueriable();
        IQueryable<Ski> GetSkisWithBrandIQueryable();
        void Create(Ski ski);
        void Update(Ski ski);
        void Delete(Ski ski);
    }
}
