using SkiProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Managers
{
    public interface ITokenManager
    {
        Task<string> GenerateToken(User user);
    }
}
