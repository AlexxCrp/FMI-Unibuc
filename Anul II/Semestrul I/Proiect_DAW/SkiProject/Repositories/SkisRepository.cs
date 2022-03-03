using SkiProject.Entities;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Repositories
{
    public class SkisRepository : ISkisRepository
    {
        private SkiProjectContext db;

        public SkisRepository(SkiProjectContext db)
        {
            this.db = db;
        }

        public IQueryable<Ski> GetSkisIQueriable()
        {
            var skis = db.Skis;
            return skis;
        }

        public IQueryable<Ski> GetSkisWithBrandIQueryable()
        {
            var skis = GetSkisIQueriable().Include(x => x.Brand);

            return skis;
        }

        public void Create(Ski ski)
        {
            db.Skis.Add(ski);
            db.SaveChanges();
        }

        public void Update(Ski ski)
        {
            db.Skis.Update(ski);
            db.SaveChanges();
        }

        public void Delete(Ski ski)
        {
            db.Skis.Remove(ski);
            db.SaveChanges();
        }
    }
}
